#pragma once

#include <QObject>

#include "Repository.h"
#include "Models/Location.h"
#include "Views/LocationListView.h"

namespace Lumen {
    class LocationController : public QObject {
        Q_OBJECT
    public:
        LocationController(Repository<QUuid, Location>* repository, LocationListView* locationListView);
        ~LocationController();

    private:
        Repository<QUuid, Location>* m_repository;
        LocationListView* m_locationListView;
    };
}
