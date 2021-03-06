set(plNetCommon_SOURCES
    plClientGuid.cpp
    plNetCommon.cpp
    plNetCommonHelpers.cpp
    plNetMember.cpp
    plNetMsgScreener.cpp
    plNetObjectDebugger.cpp
    plNetServerSessionInfo.cpp
    plSpawnPointInfo.cpp
)

set(plNetCommon_HEADERS
    plClientGuid.h
    plNetCommon.h
    plNetCommonConstants.h
    plNetCommonCreatable.h
    plNetCommonHelpers.h
    plNetMember.h
    plNetMsgHandler.h
    plNetMsgScreener.h
    plNetObjectDebugger.h
    plNetServerSessionInfo.h
    plSpawnPointInfo.h
)

add_library(plNetCommon STATIC ${plNetCommon_SOURCES} ${plNetCommon_HEADERS})

target_include_directories(plNetCommon PRIVATE "${PLASMA_SOURCE_ROOT}/FeatureLib")
target_link_libraries(plNetCommon
    PUBLIC
        CoreLib
        pnFactory
        pnKeyedObject
        pnNetCommon
        pnNetProtocol
        pnUUID
    PRIVATE
        pnMessage
        pnNucleusInc
        plCompression
        plMessage
        plNetClientComm
        plResMgr
        plStatusLog
        pfMessage # pfKIMsg in plNetMsgScreener
)

plasma_optimize_target(plNetCommon UNITY_BUILD PRECOMPILED_HEADERS Pch.h)

source_group("Source Files" FILES ${plNetCommon_SOURCES})
source_group("Header Files" FILES ${plNetCommon_HEADERS})
