PROJECT(geo)

SET(EXECUTABLE_OUTPUT_PATH ../bin)

SET(geo_INCLUDE_DIRS
	app
	lib
	lib/gui/widgets
	lib/gui/db
	lib/model/core
	lib/orm
	lib/db
	lib/dbmodel
	lib/settings
)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR} ${geo_SOURCE_DIR} ${geo_BINARY_DIR} ${geo_INCLUDE_DIRS})

IF(WIN32)
  FIND_LIBRARY(QT_GIF_PLUGIN qgif PATHS ${QT_PLUGINS_DIR} PATH_SUFFIXES imageformats)
  FIND_LIBRARY(QT_JPEG_PLUGIN qjpeg PATHS ${QT_PLUGINS_DIR} PATH_SUFFIXES imageformats)
ENDIF()

# add Qt modules here, the include will setup QT_LIBRARIES
SET(QT_USE_QTSVG TRUE)
SET(QT_USE_QTXML TRUE)
SET(QT_USE_QTSQL TRUE)

INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_QTSQL_INCLUDE_DIR} ${QT_QTSVG_INCLUDE_DIR} ${QT_QTXML_INCLUDE_DIR}) 

# .cxx sources
SET(geo_SRCS_CXX
    lib/dbmodel/DbModel.cpp
    lib/dbmodel/Schema.cpp
    lib/dbmodel/Table.cpp
    lib/dbmodel/private/DbModelData.cpp
    lib/dbmodel/private/SchemaData.cpp
    lib/dbmodel/private/TableData
    
    app/main.cpp
    app/App.cpp
    app/AppDbModel.cpp
    app/tools.cpp
    
    lib/orm/Entity.cpp
    lib/orm/IdentifiedEntity.cpp
    lib/orm/StandardEntity.cpp
    lib/orm/Mapper.cpp
    
    lib/model/core/SIPrefix.cpp
    lib/model/core/SIPrefixMapper.cpp

    lib/db/ConnectionData.cpp
    lib/db/Connection.cpp
    lib/db/QueryThread.cpp
    lib/db/TypedQuery.cpp

    lib/settings/Settings.cpp

    lib/gui/widgets/MainWindow.cpp
    lib/gui/widgets/LogDisplay.cpp
    lib/gui/widgets/LogWidget.cpp
    lib/gui/widgets/Dialog.cpp
    lib/gui/widgets/Label.cpp
    lib/gui/widgets/FieldLabel.cpp
    lib/gui/widgets/LineEdit.cpp
    lib/gui/widgets/GroupBox.cpp
    lib/gui/widgets/SmartGroupBox.cpp
    lib/gui/widgets/Editor.cpp
    lib/gui/widgets/PasswordEdit.cpp
    
    lib/gui/db/DatabaseConnectionDialog.cpp
)

# files which need to be moc'd by Qt (headers)
SET(geo_MOC_SRCS    
    app/App.h
    app/AppDbModel.h
    
    lib/dbmodel/DbModel.h
    lib/dbmodel/Schema.h
    lib/dbmodel/Table.h
    
    lib/orm/Entity.h
    lib/orm/IdentifiedEntity.h
    lib/orm/StandardEntity.h
    
    lib/model/core/SIPrefix.h
   
    lib/orm/Mapper.h
    lib/model/core/SIPrefixMapper.h
    
    lib/db/Connection.h
    lib/db/QueryThread.h

    lib/settings/Settings.h

    lib/gui/widgets/MainWindow.h
    lib/gui/widgets/LogDisplay.h
    lib/gui/widgets/LogWidget.h
    lib/gui/widgets/Dialog.h
    lib/gui/widgets/Label.h
    lib/gui/widgets/FieldLabel.h
    lib/gui/widgets/LineEdit.h
    lib/gui/widgets/GroupBox.h
    lib/gui/widgets/SmartGroupBox.h
    lib/gui/widgets/Editor.h
    lib/gui/widgets/PasswordEdit.h
    
    lib/gui/db/DatabaseConnectionDialog.h
)

# client UI files
SET(geo_UI)

# build ui_XXX files from the XML-style .ui files
QT4_WRAP_UI(geo_SRCS_CXX ${geo_UI})

# this moc's the above variable and appends to the cxx sources
QT4_WRAP_CPP(geo_SRCS_CXX ${geo_MOC_SRCS})

IF(UNIX)
  ADD_EXECUTABLE(geo ${geo_SRCS_CXX})
ELSEIF(APPLE)
  ADD_EXECUTABLE(geo MACOSX_BUNDLE ${geo_SRCS_CXX})
ELSEIF(WIN32)
  ADD_EXECUTABLE(geo WIN32 ${geo_SRCS_CXX})
ENDIF()

IF(WIN32)
  TARGET_LINK_LIBRARIES(geo ${QT_LIBRARIES} ${QT_GIF_PLUGIN} ${QT_JPEG_PLUGIN})
ELSE()
  TARGET_LINK_LIBRARIES(geo ${QT_LIBRARIES})
ENDIF()

