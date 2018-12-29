//////////////////////////////////////////////////////////////////////////
//                                                                      //
// CardinalEMS,   a graphical gauge to monitor an aircraft's engine     //
// Copyright (C) 2017 Ryan Story                                        //
//                                                                      //
// This program is free software: you can redistribute it and/or modify //
// it under the terms of the GNU General Public License as published by //
// the Free Software Foundation, either version 3 of the License, or    //
// (at your option) any later version.                                  //
//                                                                      //
// This program is distributed in the hope that it will be useful,      //
// but WITHOUT ANY WARRANTY; without even the implied warranty of       //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        //
// GNU General Public License for more details.                         //
//                                                                      //
// You should have received a copy of the GNU General Public License    //
// along with this program. If not, see <http://www.gnu.org/licenses/>. //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "spatial.h"


spatial::spatial(QObject *parent) : QObject(parent)
{
    //QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");

    
//db.setDatabaseName("C:/Users/rstor/Documents/Airplane/Avionics/ems/res/spatialite_nasr.sqlite");
    //if (!db.open()) {
    //    qDebug()<<"not open";
    //}

    //qDebug()<<enable_spatialite(db);

    //QSqlQuery query;

    //qDebug()<<query.exec("CREATE TABLE test_geom (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, measured_value DOUBLE NOT NULL);");
    //qDebug()<<query.exec("SELECT AddGeometryColumn('test_geom', 'the_geom', 4326, 'POINT', 'XY');");



//    for(int i=0; i< 10; i++){
//        QString q = QString("INSERT INTO test_geom(id, name, measured_value, the_geom) VALUES (%1,'point %2', %3, GeomFromText('POINT(1.01 2.02)', 4326))")
//                .arg("NULL").arg(i).arg(i);
//        query.prepare(q);
//        qDebug()<< i<<query.exec();
//    }

    //qDebug()<<query.exec("SELECT id, name, measured_value,  AsText(the_geom), 
//ST_GeometryType(the_geom), ST_Srid(the_geom) FROM test_geom");


    //while (query.next()) {
    //    QString str;
    //    for(int i=0; i < query.record().count(); i++)
    //        str += query.value(i).toString() + " ";
    //    qDebug()<<str;
    //}
}

/*int spatial::enable_spatialite(QSqlDatabase db){
    QVariant v = db.driver()->handle();
    if (v.isValid() && qstrcmp(v.typeName(), "sqlite3*") == 0)
    {
        sqlite3_initialize();
        sqlite3 *db_handle = *static_cast<sqlite3 **>(v.data());

        if (db_handle != 0) {

            sqlite3_enable_load_extension(db_handle, 1);

            QSqlQueryModel sql;
            sql.setQuery("SELECT load_extension('mod_spatialite')", db);
            if (sql.lastError().isValid())
            {
                qDebug() << "Error: cannot load the Spatialite extension (" << sql.lastError().text()<<")";
                return 0;
            }
            else    return 1;
        }
    }
    return 0;
}*/


