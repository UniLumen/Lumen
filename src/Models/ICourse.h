#pragma once

#include "Instructor.h"
#include "Lecture.h"
#include "Section.h"

namespace Lumen {
    class ICourse {
    public:
        virtual QUuid id() const = 0;
        virtual QString name() const = 0;
        virtual QString code() const = 0;
        virtual int creditHours() const = 0;
        virtual bool hasLecture() const = 0;
        virtual bool hasLab() const = 0;
        virtual bool hasTutorial() const = 0;
        virtual QList<Lecture> lectures() const = 0;
        virtual QList<Section> sections() const = 0;
        virtual QList<const Instructor*> doctors() const = 0;

        virtual void setName(const QString& name) = 0;
        virtual void setCode(const QString& code) = 0;
        virtual bool setCreditHours(int creditHours) = 0;
        virtual void setCourseComponents(unsigned int components) = 0;
    };
}
