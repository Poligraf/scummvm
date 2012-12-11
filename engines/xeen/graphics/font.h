/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef XEEN_FONT_H
#define XEEN_FONT_H

#include "xeen/utility.h"
#include "xeen/archive/file.h"

namespace XEEN
{
    class Game;
    class ImageBuffer;

    // Only accessible by Game
    class Font : public Validateable, public Common::NonCopyable
    {
        friend class Game;
    
        public:
            static const uint32 SMALL = 1;
            static const uint32 CENTER = 2;
            static const uint32 ALIGN_RIGHT = 4;

        private:
            Font();

            void drawString(ImageBuffer& out, Common::Point pen, const char* text, uint32 flags = 0, uint32 width = 0) const;
            uint32 measureString(const char* text, uint32 flags) const;
            
        private:
            FilePtr _data;
    };
}

#endif // XEEN_FONT_H