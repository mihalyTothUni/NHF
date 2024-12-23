#include <iostream>


#include "film.h"
#include "family.h"
#include "documentary.h"
#include "database.h"
#include "gtest_lite.h"
#include "memtrace.h"

#define testing 5

int main() {

//Database funkciok tesztelese
#if testing > 0
    //search function test
    TEST(Database, DatabaseSearchTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        std::stringstream ss;
        db.searchAndList("Family_title", ss);
        EXPECT_EQ(ss.str(), "Family\tFamily_title\t120\t2000\t12\n");
    } ENDM
#endif
#if testing > 1
    //export fuction test
    TEST(Database, DatabaseExportTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        db.exportdb("test.txt");
        std::ifstream file("test.txt");
        std::string line1, line2;
        std::string expected1 = "Family\tFamily_title\t120\t2000\t12";
        std::string expected2 = "Documentary\tDocumentary_title\t130\t2010\tDescription";
        std::getline(file, line1);
        std::getline(file, line2);
        EXPECT_EQ(line1, expected1);
        EXPECT_EQ(line2, expected2);
    } ENDM
#endif
#if testing > 2
    //import function test
    TEST(Database, DatabaseImportTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        db.exportdb("test.txt");
        Database db2(db);
        db.clear();
        db.import("test.txt");
        EXPECT_EQ(db2 == db, true);
    } ENDM
#endif
#if testing > 3
    //remove function test
    try{
    TEST(Database, DatabaseRemoveTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        db.remove("Family_title");
        std::stringstream ss;
        db.listAll(ss);
        EXPECT_EQ(ss.str(), "Documentary\tDocumentary_title\t130\t2010\tDescription\n");
    } ENDM
    } catch (const char* e) {
        std::cout  << e << std::endl;
    }
#endif

///error handling tests
#if testing > 4
    //search function error handling
    TEST(Database, DatabaseSearchErrorTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        std::stringstream ss;
        try {
            db.searchAndList("Family_title2", ss);
        } catch (const char* e) {
            EXPECT_STREQ(e, "entry not found");
        }
    } ENDM
    //remove function error handling
    TEST(Database, DatabaseRemoveErrorTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        try {
            db.remove("Family_title2");
        } catch (const char* e) {
            EXPECT_STREQ(e, "entry not found");
        }
    } ENDM
    //import function error handling
    TEST(Database, DatabaseImportErrorTest) {
        Database db;
        try {
            db.import("test2.txt");
        } catch (const char* e) {
            EXPECT_STREQ(e, "file not found");
        }
    } ENDM
#endif
#if testing < 5
    ADD_FAILURE() << "Missing tests!";
#endif
    return 0;
}
