#ifndef DATABASE_H
#define DATABASE_H

// https://doc.qt.io/qt-5/qcoreapplication.html //
// https://doc.qt.io/qt-5/qdir.html //

// https://doc.qt.io/qt-5/qsqldatabase.html //
// https://doc.qt.io/qt-5/qsqlquery.html //
// https://doc.qt.io/qt-5/qsqlrecord.html //
// https://doc.qt.io/qt-5/qsqlresult.html //

// http://www.cplusplus.com/reference/string/string/ //

// https://katecpp.wordpress.com/2015/08/28/sqlite-with-qt/ //
// http://blog.davidecoppola.com/2016/11/howto-embed-database-in-application-with-sqlite-and-qt/ //

#include <QCoreApplication>
#include <QDir>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <string>

#include <QSqlResult>
#include <QSqlRecord>

#include <QVariant>

class DataBase
{
    public:
        DataBase();
        bool getStateConnection();
        char executeSQL( std::string sql );
        int numberRowsAffected();
        int numberRowsReturned();
        bool previousRegister();
        bool nextRegister();
        std::string returnValue( std::string field );
        void clearQuery();
        void closeConnection();

    private:
        QSqlDatabase database;
        bool stateConnection;
        QSqlQuery query;

};

#endif // DATABASE_H
