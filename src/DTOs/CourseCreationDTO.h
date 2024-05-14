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
        bool hasMandatoryLecture;
        bool hasMandatoryLab;
        bool hasMandatoryTutorial;

        Course* toCourse() const {
            unsigned int courseComponents = 0;
            unsigned int mandatoryComponents = 0;

            if (hasLecture) {
                courseComponents |= Course::LectureComponent;
            }
            if (hasLab) {
                courseComponents |= Course::LabComponent;
            }
            if (hasTutorial) {
                courseComponents |= Course::TutorialComponent;
            }

            if (hasMandatoryLecture) {
                mandatoryComponents |= Course::LectureComponent;
            }
            if (hasMandatoryLab) {
                mandatoryComponents |= Course::LabComponent;
            }
            if (hasMandatoryTutorial) {
                mandatoryComponents |= Course::TutorialComponent;
            }

            return new Course(name, code, dept, year, creditHours, mandatoryComponents, courseComponents);
        }
    };    
}
