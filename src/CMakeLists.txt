PROJECT(geo)

SET(EXECUTABLE_OUTPUT_PATH ../bin)

SET(geo_INCLUDE_DIRS
	App
	Lib
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
    Lib/DBModel/XMLParser.cpp
    Lib/DBModel/ModelComponent.cpp
    Lib/DBModel/DBModel.cpp
    Lib/DBModel/InDBModelComponent.cpp
    Lib/DBModel/InSchemaModelComponent.cpp
    Lib/DBModel/InTableModelComponent.cpp
    Lib/DBModel/Schema.cpp
    Lib/DBModel/Table.cpp
    Lib/DBModel/Sequence.cpp
    Lib/DBModel/DataType.cpp
    Lib/DBModel/TableColumn.cpp
    Lib/DBModel/TableConstraint.cpp
    Lib/DBModel/PrimaryKeyConstraint.cpp
    Lib/DBModel/UniqueConstraint.cpp
    Lib/DBModel/CheckConstraint.cpp
    Lib/DBModel/TableColumnPair.cpp
    Lib/DBModel/ForeignKeyConstraint.cpp
    Lib/DBModel/private/Base.cpp
    Lib/DBModel/private/DBModelData.cpp
    Lib/DBModel/private/SchemaData.cpp
    Lib/DBModel/private/TableData.cpp
    Lib/DBModel/private/DataTypeData.cpp
    Lib/DBModel/private/SequenceData.cpp
    Lib/DBModel/private/TableColumnData.cpp
    Lib/DBModel/private/ConstraintData.cpp
    Lib/DBModel/private/PrimaryKeyConstraintData.cpp
    Lib/DBModel/private/UniqueConstraintData.cpp
    Lib/DBModel/private/CheckConstraintData.cpp
    Lib/DBModel/private/ForeignKeyConstraintData.cpp
    
    Lib/Tools/tools.cpp
    
    App/main.cpp
    App/App.cpp
    
    Lib/ORM/Entity.cpp
    Lib/ORM/EntityData.cpp
    Lib/ORM/IdentifiedEntity.cpp
    Lib/ORM/IdentifiedEntityData.cpp
    Lib/ORM/StandardEntity.cpp
    Lib/ORM/StandardEntityData.cpp
    Lib/ORM/Mapper.cpp
    
    Lib/Model/core/SIPrefix.cpp
    Lib/Model/core/SIPrefixMapper.cpp
    Lib/Model/core/private/SIPrefixData.cpp
    
    Lib/DB/ConnectionData.cpp
    Lib/DB/Connection.cpp
    Lib/DB/QueryThread.cpp
    Lib/DB/TypedQuery.cpp

    Lib/Settings/Settings.cpp

    Lib/GUI/Widgets/MainWindow.cpp
    Lib/GUI/Widgets/LogDisplay.cpp
    Lib/GUI/Widgets/LogWidget.cpp
    Lib/GUI/Widgets/Dialog.cpp
    Lib/GUI/Widgets/Label.cpp
    Lib/GUI/Widgets/FieldLabel.cpp
    Lib/GUI/Widgets/LineEdit.cpp
    Lib/GUI/Widgets/GroupBox.cpp
    Lib/GUI/Widgets/SmartGroupBox.cpp
    Lib/GUI/Widgets/Editor.cpp
    Lib/GUI/Widgets/PasswordEdit.cpp
    
    Lib/Gui/DB/DatabaseConnectionDialog.cpp
)

# files which need to be moc'd by Qt (headers)
SET(geo_MOC_SRCS    
    App/App.h
    
    Lib/DBModel/XMLParser.h
    Lib/DBModel/ModelComponent.h
    Lib/DBModel/DBModel.h
    Lib/DBModel/InDBModelComponent.h
    Lib/DBModel/InSchemaModelComponent.h
    Lib/DBModel/InTableModelComponent.h
    Lib/DBModel/TableConstraint.h
    Lib/DBModel/Schema.h
    Lib/DBModel/Table.h
    Lib/DBModel/TableColumn.h
    Lib/DBModel/DataType.h
    Lib/DBModel/Sequence.h
    Lib/DBModel/PrimaryKeyConstraint.h
    Lib/DBModel/UniqueConstraint.h
    Lib/DBModel/CheckConstraint.h
    Lib/DBModel/ForeignKeyConstraint.h
    
    Lib/ORM/Entity.h
    Lib/ORM/IdentifiedEntity.h
    Lib/ORM/StandardEntity.h
    Lib/ORM/Mapper.h
    
    Lib/Model/core/SIPrefix.h
   
   Lib/Model/core/SIPrefixMapper.h
    
    Lib/DB/Connection.h
    Lib/DB/QueryThread.h

    Lib/Settings/Settings.h

    Lib/GUI/Widgets/MainWindow.h
    Lib/GUI/Widgets/LogDisplay.h
    Lib/GUI/Widgets/LogWidget.h
    Lib/GUI/Widgets/Dialog.h
    Lib/GUI/Widgets/Label.h
    Lib/GUI/Widgets/FieldLabel.h
    Lib/GUI/Widgets/LineEdit.h
    Lib/GUI/Widgets/GroupBox.h
    Lib/GUI/Widgets/SmartGroupBox.h
    Lib/GUI/Widgets/Editor.h
    Lib/GUI/Widgets/PasswordEdit.h
    
    Lib/Gui/DB/DatabaseConnectionDialog.h
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

