#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := simple

EXTRA_COMPONENT_DIRS = $(IDF_PATH)/examples/common_components/protocol_examples_common
EXTRA_COMPONENT_DIRS += $(PROJECT_PATH)/../libs/esp32-idf-sqlite3/

include $(IDF_PATH)/make/project.mk

