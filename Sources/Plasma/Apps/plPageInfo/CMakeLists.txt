set(plPageInfo_SOURCES
    plAllCreatables.cpp
    plPageInfo.cpp
)

add_executable(plPageInfo ${plPageInfo_SOURCES})
target_link_libraries(
    plPageInfo
    PRIVATE
        CoreLib
        pnDispatch
        pnFactory
        pnKeyedObject
        pnMessage
        pnModifier
        pnNetCommon
        pnNucleusInc
        plAgeDescription
        plAudioCore
        plMessage
        plResMgr
)

install(
    TARGETS plPageInfo
    DESTINATION tools_cli
)

source_group("Source Files" FILES ${plPageInfo_SOURCES})
