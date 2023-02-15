cmake_minimum_required(VERSION 3.0.0)

SET(PROJECT_NAME Hausaufgabe)
PROJECT(${PROJECT_NAME} C)

FILE(GLOB HA1 Hausaufgabe1/*c Hausaufgabe1/*.h)
ADD_EXECUTABLE(HA1 ${HA1})

FILE(GLOB HA2 Hausaufgabe2/*c Hausaufgabe2/*.h)
ADD_EXECUTABLE(HA2 ${HA2})

FILE(GLOB HA3 Hausaufgabe3/*c Hausaufgabe3/*.h)
ADD_EXECUTABLE(HA3 ${HA3})

FILE(GLOB HA4 Hausaufgabe4/*c Hausaufgabe4/*.h)
ADD_EXECUTABLE(HA4 ${HA4})