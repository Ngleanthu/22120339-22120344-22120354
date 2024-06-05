#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const std::string loginDataFile   = "login.csv";
const std::string profileDataFile = "profile.csv";
const std::string courseDataFile  = "course.csv";
const std::string classDataFile   = "class.csv";
const std::string scoreDataFile   = "score.csv";
const std::string schoolYearFile  = "schoolyear.csv";
const std::string semesterFile    = "semester.csv";

const std::string dataDirectory = "./db/";


const std::string schoolYearCSVHeader[] = {"id", "school_year", "start_year", "end_year"};
const std::string semesterHeader[] = {"id", "semester_number", "school_year_id", "start_date", "end_date"};

#endif