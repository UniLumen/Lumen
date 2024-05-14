#pragma once

#include <QtCore>

#include "Models/Course.h"

namespace Lumen {
    struct CourseCreationDTO {
        QString name;
        QString code;
        QString dept;
        int year;
        int creditHours;
        bool hasLecture;
        bool hasLab;
        bool hasTutorial;
        bool isLectureMandatory;
        bool isLabMandatory;
        bool isTutorialMandatory;

        Course* toCourse() const {
            return new Course(name, code, creditHours);
        }
    };    
}
