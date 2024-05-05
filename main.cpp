#include <iostream>


#include "film.h"
#include "family.h"
#include "documentary.h"
#include "database.h"
#include "filehandler.h"


#include "memtrace.h"
#include "gtest_lite.h"

#define testing 7

int main() {

#if testing > 0
    //film class test
    TEST(Family, FamilyTest) {
        Family f("Family", 120, 2000, 12);
        EXPECT_EQ(f.getTitle(), "Family");
        EXPECT_EQ(f.getRuntime(), 120);
        EXPECT_EQ(f.getRelease(), 2000);
        EXPECT_EQ(f.getRating(), 12);
    } ENDM

    //documentary class test
    TEST(Documentary, DocumentaryTest) {
        Documentary d("Documentary", 120, 2000, "Description");
        EXPECT_EQ(d.getTitle(), "Documentary");
        EXPECT_EQ(d.getRuntime(), 120);
        EXPECT_EQ(d.getRelease(), 2000);
        EXPECT_EQ(d.getDescription(), "Description");
    } ENDM
#endif
#if testing > 1
    //database class test
    TEST(Database, DatabaseTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        db.add(new Documentary("Documentary_title2", 130, 2010, "Description2"));
        std::stringstream ss;
        db.listAll(ss);
        EXPECT_EQ(ss.str(), "Family\tFamily_title\t120\t2000\t12\n"
                            "Documentary\tDocumentary_title\t130\t2010\tDescription\n"
                            "Documentary\tDocumentary_title2\t130\t2010\tDescription2\n");
    } ENDM
#endif

//Database funkciok tesztelese
#if testing > 2
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
#if testing > 3
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
#if testing > 4
    //import function test
    TEST(Database, DatabaseImportTest) {
        Database db;
        db.import("test.txt");
        std::stringstream ss;
        db.listAll(ss);
        EXPECT_EQ(ss.str(), "Family\tFamily_title\t120\t2000\t12\n"
                            "Documentary\tDocumentary_title\t130\t2010\tDescription\n");
    } ENDM
#endif
#if testing > 5
    //remove function test
    TEST(Database, DatabaseRemoveTest) {
        Database db;
        db.add(new Family("Family_title", 120, 2000, 12));
        db.add(new Documentary("Documentary_title", 130, 2010, "Description"));
        db.remove("Family_title");
        std::stringstream ss;
        db.listAll(ss);
        EXPECT_EQ(ss.str(), "Documentary\tDocumentary_title\t130\t2010\tDescription\n");
    } ENDM
#endif

///error handling tests
#if testing > 6
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
#if testing < 7
    ADD_FAILURE() << "Missing tests!";
#endif
    return 0;
}
