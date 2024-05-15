#include "LocationController.h"

LocationController::LocationController(Repository<QUuid, Location>* repository, LocationListView* locationListView)
    : m_repository(repository), m_locationListView(locationListView) {
    QVector<const Location*> locations;
    for (const auto& l : repository->getAll()) {
        locations.push_back(l);
    }
    m_locationListView->setLocations(locations);

    QObject::connect(m_locationListView, &LocationListView::createLocationRequest, this,
                     [&](const QString& name, const QString& building, int floor, const QString& description) {
                         Location* location = new Location(name, building, floor, description);
                         m_repository->insert(location->id(), location);
                         m_locationListView->addLocation(location);
                     });

    QObject::connect(m_locationListView, &LocationListView::removeLocationRequest, this, [&](int index) {
        const Location* removedLocation = m_locationListView->removeLocation(index);
        if (removedLocation) {
            m_repository->remove(removedLocation->id());
        }
    });
}

LocationController::~LocationController() {
    QObject::disconnect(m_locationListView, nullptr, this, nullptr);
}
