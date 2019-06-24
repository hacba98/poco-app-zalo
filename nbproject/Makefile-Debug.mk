#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/FriendServicesHandler.o \
	${OBJECTDIR}/MyDB.o \
	${OBJECTDIR}/SubCache.o \
	${OBJECTDIR}/SubHandler.o \
	${OBJECTDIR}/SubKC.o \
	${OBJECTDIR}/gen-cpp/FriendServices.o \
	${OBJECTDIR}/gen-cpp/friend_service_constants.o \
	${OBJECTDIR}/gen-cpp/friend_service_types.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../Poco -L../KC ../Poco/libpoco.a ../KC/libkc.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serverapplication

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serverapplication: ../Poco/libpoco.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serverapplication: ../KC/libkc.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serverapplication: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serverapplication ${OBJECTFILES} ${LDLIBSOPTIONS} -pthread -lthrift

${OBJECTDIR}/FriendServicesHandler.o: FriendServicesHandler.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FriendServicesHandler.o FriendServicesHandler.cpp

${OBJECTDIR}/MyDB.o: MyDB.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyDB.o MyDB.cpp

${OBJECTDIR}/SubCache.o: SubCache.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SubCache.o SubCache.cpp

${OBJECTDIR}/SubHandler.o: SubHandler.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SubHandler.o SubHandler.cpp

${OBJECTDIR}/SubKC.o: SubKC.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SubKC.o SubKC.cpp

${OBJECTDIR}/gen-cpp/FriendServices.o: gen-cpp/FriendServices.cpp
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gen-cpp/FriendServices.o gen-cpp/FriendServices.cpp

${OBJECTDIR}/gen-cpp/friend_service_constants.o: gen-cpp/friend_service_constants.cpp
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gen-cpp/friend_service_constants.o gen-cpp/friend_service_constants.cpp

${OBJECTDIR}/gen-cpp/friend_service_types.o: gen-cpp/friend_service_types.cpp
	${MKDIR} -p ${OBJECTDIR}/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gen-cpp/friend_service_types.o gen-cpp/friend_service_types.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../Poco/include -I../KC -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
