PROJECT(geologist)

SET(EXECUTABLE_OUTPUT_PATH ../bin)

SET(geologist_INCLUDE_DIRS
	App
	Lib
)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR} ${geologist_SOURCE_DIR} ${geologist_BINARY_DIR} ${geologist_INCLUDE_DIRS})

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

SET(geologist_Lib_DBModel_SRCS_CXX
    Lib/DBModel/DBXMLParser.cpp
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
    Lib/DBModel/Private/Base.cpp
    Lib/DBModel/Private/DBModelData.cpp
    Lib/DBModel/Private/SchemaData.cpp
    Lib/DBModel/Private/TableData.cpp
    Lib/DBModel/Private/DataTypeData.cpp
    Lib/DBModel/Private/SequenceData.cpp
    Lib/DBModel/Private/TableColumnData.cpp
    Lib/DBModel/Private/ConstraintData.cpp
    Lib/DBModel/Private/PrimaryKeyConstraintData.cpp
    Lib/DBModel/Private/UniqueConstraintData.cpp
    Lib/DBModel/Private/CheckConstraintData.cpp
    Lib/DBModel/Private/ForeignKeyConstraintData.cpp
)

SET(geologist_Lib_DBModel_MOC_SRCS
    Lib/DBModel/DBXMLParser.h
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
)

SET(geologist_Lib_Tools_SRCS_CXX
    Lib/Tools/tools.cpp
    Lib/Tools/XMLFileParser.cpp
)

SET(geologist_Lib_Tooles_MOC_SRCS
    Lib/Tools/XMLFileParser.h
)

SET(geologist_App_SRCS_CXX
    App/main.cpp
    App/App.cpp
)

SET(geologist_App_MOC_SRCS
    App/App.h
)

SET(geologist_Lib_ORM_SRCS_CXX
    Lib/ORM/Entity.cpp
    Lib/ORM/IdentifiedEntity.cpp
    Lib/ORM/StandardEntity.cpp
    Lib/ORM/Query.cpp
    Lib/ORM/CursorQuery.cpp
    Lib/ORM/DeclareCursorQuery.cpp
    Lib/ORM/DeclareSelectCursorQuery.cpp
    Lib/ORM/CloseCursorQuery.cpp
    Lib/ORM/FetchAllInCursorQuery.cpp

    Lib/ORM/Private/EntityData.cpp
    Lib/ORM/Private/IdentifiedEntityData.cpp
    Lib/ORM/Private/StandardEntityData.cpp

    Lib/ORM/EntityStatus.cpp
    Lib/ORM/DataManager.cpp
    Lib/ORM/Mapping.cpp
    Lib/ORM/Property.cpp
    Lib/ORM/MappingXMLParser.cpp
    Lib/ORM/Private/MappingData.cpp
)

SET(geologist_Lib_ORM_MOC_SRCS
    Lib/ORM/Entity.h
    Lib/ORM/IdentifiedEntity.h
    Lib/ORM/StandardEntity.h

    Lib/ORM/MappingXMLParser.h
    Lib/ORM/DataManager.h
    Lib/ORM/Mapping.h
    Lib/ORM/Property.h
)

SET(geologist_Lib_Model_Core_SRCS_CXX
    Lib/Model/Core/SIPrefix.cpp
    Lib/Model/Core/Private/SIPrefixData.cpp
)

SET(geologist_Lib_Model_Core_MOC_SRCS
    Lib/Model/Core/SIPrefix.h
)

SET(geologist_Lib_DB_SRCS_CXX
    Lib/DB/ConnectionData.cpp
    Lib/DB/Connection.cpp
    Lib/DB/QueryThread.cpp
    Lib/DB/DatabaseError.cpp
)

SET(geologist_Lib_DB_MOC_SRCS
    Lib/DB/Connection.h
    Lib/DB/QueryThread.h
)

SET(geologist_Lib_Settings_SRCS_CXX
    Lib/Settings/Settings.cpp
)

SET(geologist_Lib_Settings_MOC_SRCS
    Lib/Settings/Settings.h
)

SET(geologist_Lib_GUI_Widgets_SRCS_CXX
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
)


SET(geologist_Lib_GUI_Widgets_MOC_SRCS
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
)

SET(geologist_Lib_GUI_DB_SRCS_CXX
    Lib/GUI/DB/DatabaseConnectionDialog.cpp
)

SET(geologist_Lib_GUI_DB_MOC_SRCS
    Lib/GUI/DB/DatabaseConnectionDialog.h
)

# .cxx sources
SET(geologist_SRCS_CXX
    ${geologist_Lib_Tools_SRCS_CXX}
    ${geologist_Lib_Settings_SRCS_CXX}
    ${geologist_Lib_DBModel_SRCS_CXX}
    ${geologist_Lib_ORM_SRCS_CXX}
    ${geologist_Lib_DB_SRCS_CXX}
    ${geologist_Lib_Model_Core_SRCS_CXX}
    ${geologist_Lib_GUI_Widgets_SRCS_CXX}
    ${geologist_Lib_GUI_DB_SRCS_CXX}
    ${geologist_App_SRCS_CXX}
)

# files which need to be moc'd by Qt (headers)
SET(geologist_MOC_SRCS
    ${geologist_Lib_Tooles_MOC_SRCS}
    ${geologist_App_MOC_SRCS}
    ${geologist_Lib_DBModel_MOC_SRCS}
    ${geologist_Lib_ORM_MOC_SRCS}
    ${geologist_Lib_Model_Core_MOC_SRCS}
    ${geologist_Lib_DB_MOC_SRCS}
    ${geologist_Lib_Settings_MOC_SRCS}
    ${geologist_Lib_GUI_Widgets_MOC_SRCS}
    ${geologist_Lib_GUI_DB_MOC_SRCS}
)

# client UI files
SET(geologist_UI)

# build ui_XXX files from the XML-style .ui files
QT4_WRAP_UI(geologist_SRCS_CXX ${geologist_UI})

# this moc's the above variable and appends to the cxx sources
QT4_WRAP_CPP(geologist_SRCS_CXX ${geologist_MOC_SRCS})

IF(UNIX)
  ADD_EXECUTABLE(geologist ${geologist_SRCS_CXX})
ELSEIF(APPLE)
  ADD_EXECUTABLE(geologist MACOSX_BUNDLE ${geologist_SRCS_CXX})
ELSEIF(WIN32)
  ADD_EXECUTABLE(geologist WIN32 ${geologist_SRCS_CXX})
ENDIF()

IF(WIN32)
  TARGET_LINK_LIBRARIES(geologist ${QT_LIBRARIES} ${QT_GIF_PLUGIN} ${QT_JPEG_PLUGIN})
ELSE()
  TARGET_LINK_LIBRARIES(geologist ${QT_LIBRARIES})
ENDIF()
