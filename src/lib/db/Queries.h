#ifndef QUERIES_H
#define QUERIES_H

class Queries {
public:
	enum QueryId {
		None = 0,
		CurrentUser,
		CurrentTimestamp,

		AllSIPrefixesOpenCursor,
		AllSIPrefixesFetchAll,
		AllSIPrefixesCloseCursor
	};
};
#endif
