set(pfConsole_SOURCES
    pfAudioConsoleCommands.cpp
    pfAvatarConsoleCommands.cpp
    pfConsole.cpp
    pfConsoleCommands.cpp
    pfConsoleCommandsNet.cpp
    pfConsoleDirSrc.cpp
    pfDispatchLog.cpp
    pfGameConsoleCommands.cpp
)

set(pfConsole_HEADERS
    pfConsole.h
    pfConsoleCreatable.h
    pfConsoleDirSrc.h
    pfDispatchLog.h
)

add_library(pfConsole STATIC ${pfConsole_SOURCES} ${pfConsole_HEADERS})
target_link_libraries(
    pfConsole
    PUBLIC
        CoreLib
        pnDispatch
        pnKeyedObject
        pfConsoleCore
    PRIVATE
        pnInputCore
        pnMessage
        pnNetCommon
        pnNucleusInc
        pnSceneObject
        pnTimer
        pnUUID
        plAgeDescription
        plAgeLoader
        plAnimation
        plAudio
        plAvatar
        plDrawable
        plGImage
        plGLight
        plInputCore
        plNetClient
        plNetCommon
        plNetGameLib
        plNetMessage
        plMessage
        plModifier
        plParticleSystem
        plPhysical
        plPhysX
        plPipeline
        pfPython
        plResMgr
        plScene
        plSDL
        plStatGather
        plStatusLog
        plSurface
        plUnifiedTime
        plVault
        pfAudio
        pfAnimation
        pfCamera
        pfGameGUIMgr
        pfMessage
        pfPython
        pfSurface
    INTERFACE
        pnFactory
)

plasma_optimize_target(pfConsole PRECOMPILED_HEADERS Pch.h)

source_group("Source Files" FILES ${pfConsole_SOURCES})
source_group("Header Files" FILES ${pfConsole_HEADERS})
