QT += core
QT -= gui

CONFIG += c++11

TARGET = containers
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONTAINERS_ROOT = $${PWD}
SRC = $${CONTAINERS_ROOT}/src
VECTOR = $${SRC}/vector
LINKED_LIST = $${SRC}/linked_list
DOUBLY_LINKED_LIST = $${SRC}/doubly_linked_list

SOURCES += main.cpp \

HEADERS += $${VECTOR}/vector.h \
           $${LINKED_LIST}/linked_list.h

DESTDIR = "$${CONTAINERS_ROOT}/bin"
OBJECTS_DIR = "$${CONTAINERS_ROOT}/tmp/obj"
MOC_DIR = "$${CONTAINERS_ROOT}/tmp/moc"
UI_DIR = "$${CONTAINERS_ROOT}/tmp/uic"
RCC_DIR = "$${CONTAINERS_ROOT}/tmp/rcc"
