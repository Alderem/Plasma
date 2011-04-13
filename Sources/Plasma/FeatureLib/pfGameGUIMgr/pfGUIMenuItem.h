/*==LICENSE==*

CyanWorlds.com Engine - MMOG client, server and tools
Copyright (C) 2011  Cyan Worlds, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

You can contact Cyan Worlds, Inc. by email legal@cyan.com
 or by snail mail at:
      Cyan Worlds, Inc.
      14617 N Newport Hwy
      Mead, WA   99021

*==LICENSE==*/
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//  pfGUIMenuItem Header                                                    //
//                                                                          //
//  The type of button that knows how to party.                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef _pfGUIMenuItem_h
#define _pfGUIMenuItem_h

#include "pfGUIButtonMod.h"

class plMessage;

class pfGUISkin;
class pfGUIMenuItem : public pfGUIButtonMod
{
    public:
        enum HowToSkin
        {
            kTop,
            kMiddle,
            kBottom
        };

    protected:

        wchar_t         *fName;
        hsBool          fReportingHover;

        HowToSkin       fHowToSkin;
        hsBool          fSkinBuffersUpdated;

        virtual void    IGrowDTMDimsToDesiredSize( UInt16 &width, UInt16 &height );
        virtual void    IPostSetUpDynTextMap( void );
        virtual void    IUpdate( void );

        void            IUpdateSkinBuffers( void );
        void            IUpdateSingleSkinBuffer( UInt16 y, hsBool sel );

    public:

        pfGUIMenuItem();
        virtual ~pfGUIMenuItem();

        CLASSNAME_REGISTER( pfGUIMenuItem );
        GETINTERFACE_ANY( pfGUIMenuItem, pfGUIButtonMod );

        enum ItemFlags
        {
            kDrawSubMenuArrow = kDerivedFlagsStart,
            kReportHovers
        };

        // Extended event types
        enum ExtendedEvents
        {
            kMouseHover,
            kMouseExit
        };

        virtual hsBool  MsgReceive( plMessage* pMsg );
        
        virtual void Read( hsStream* s, hsResMgr* mgr );
        virtual void Write( hsStream* s, hsResMgr* mgr );

        virtual void    SetInteresting( hsBool i );

        virtual void    HandleMouseDown( hsPoint3 &mousePt, UInt8 modifiers );
        virtual void    HandleMouseUp( hsPoint3 &mousePt, UInt8 modifiers );
        virtual void    HandleMouseDrag( hsPoint3 &mousePt, UInt8 modifiers );
        virtual void    HandleMouseHover( hsPoint3 &mousePt, UInt8 modifiers );

        virtual void    PurgeDynaTextMapImage();


        void        SetName( const char *name );
        void        SetName( const wchar_t *name );
        const wchar_t   *GetName( void ) const { return fName; }
    
        void    GetTextExtents( UInt16 &width, UInt16 &height );

        void    SetSkin( pfGUISkin *skin, HowToSkin s );
};

#endif // _pfGUIMenuItem_h