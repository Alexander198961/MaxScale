add_library(gssapiauth SHARED gssapi_auth.c ../gssapi_auth_common.c)
target_link_libraries(gssapiauth maxscale-common ${GSSAPI_LIBS} ${SQLITE_LIBRARIES} mysqlcommon)
set_target_properties(gssapiauth PROPERTIES VERSION "1.0.0")
install_module(gssapiauth core)
