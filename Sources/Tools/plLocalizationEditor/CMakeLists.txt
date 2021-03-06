set(plLocalizationEditor_HEADERS
    plAddDlgs.h
    plEditDlg.h
    plLocTreeView.h
)

set(plLocalizationEditor_SOURCES
    plAddDlgs.cpp
    plEditDlg.cpp
    plLocalizationEditor.cpp
    plLocTreeView.cpp
)

if(WIN32)
    list(APPEND plLocalizationEditor_SOURCES
        res/plLocalizationEditor.rc
    )
endif()

set(plLocalizationEditor_RCC
    res/plLocalizationEditor.qrc
)

set(plLocalizationEditor_UIC
    res/EditDialog.ui
    res/AddElement.ui
    res/AddLocalization.ui
)

add_executable(plLocalizationEditor WIN32 MACOSX_BUNDLE
               ${plLocalizationEditor_HEADERS} ${plLocalizationEditor_SOURCES}
               ${plLocalizationEditor_RCC} ${plLocalizationEditor_UIC})
target_link_libraries(
    plLocalizationEditor
    PRIVATE
        CoreLib
        pnNucleusInc
        plMessage
        plResMgr
        pfLocalizationMgr
        Qt5::Widgets
)

set_target_properties(
    plLocalizationEditor
    PROPERTIES
        AUTOMOC ON
        AUTORCC ON
        AUTOUIC ON
)

target_include_directories(
    plLocalizationEditor
    PRIVATE
        # Needed for custom widget include in EditDialog.ui
        ${CMAKE_CURRENT_SOURCE_DIR}
)

source_group("Source Files" FILES ${plLocalizationEditor_SOURCES} ${plLocalizationEditor_MOC})
source_group("Header Files" FILES ${plLocalizationEditor_HEADERS})
source_group("Resource Files" FILES ${plLocalizationEditor_RCC} ${plLocalizationEditor_UIC})
