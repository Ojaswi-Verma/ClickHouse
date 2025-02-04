#pragma once

#include <Interpreters/Context_fwd.h>
#include <Parsers/IAST.h>

#include <boost/noncopyable.hpp>


namespace DB
{

enum class UserDefinedSQLObjectType
{
    Function
};

class UserDefinedSQLObjectsLoader : private boost::noncopyable
{
public:
    static UserDefinedSQLObjectsLoader & instance();
    UserDefinedSQLObjectsLoader();

    void loadObjects(ContextPtr context);
    void storeObject(ContextPtr context, UserDefinedSQLObjectType object_type, const String & object_name, const IAST & ast);
    void removeObject(ContextPtr context, UserDefinedSQLObjectType object_type, const String & object_name);

private:

    void loadUserDefinedObject(ContextPtr context, UserDefinedSQLObjectType object_type, const std::string_view & object_name, const String & file_path);
    Poco::Logger * log;
};

}
