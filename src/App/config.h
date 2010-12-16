#ifndef CONFIG_H
#define CONFIG_H

#define APP_VERSION "0.1"
#define APP_NAME "general"
#define ORG_DOMAIN "johanneslochmann.blogspot.com"
#define ORG_NAME "LochiSoft"

#define DB_NAME "test"
#ifdef Q_OS_UNIX
#define DB_CONFIG_FILE "/home/jolo/projects/geologist/src/App/XML/db.xml"
#define MAPPING_CONFIG_FILE "/home/jolo/projects/geologist/src/App/XML/mapping.xml"
#ifdef Q_OS_MAC
#undef DB_CONFIG_FILE
#undef MAPPING_CONFIG_FILE
#define DB_CONFIG_FILE "/Users/jolo/data/coding/geologist/src/App/XML/db.xml"
#define MAPPING_CONFIG_FILE "/Users/jolo/data/coding/geologist/src/App/XML/mapping.xml"
#endif // Q_OS_MAC
#endif
#endif
