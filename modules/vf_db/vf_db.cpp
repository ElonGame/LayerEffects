/*============================================================================*/
/*
  VFLib: https://github.com/vinniefalco/VFLib

  Copyright (C) 2008 by Vinnie Falco <vinnie.falco@gmail.com>

  This library contains portions of other open source products covered by
  separate licenses. Please see the corresponding source files for specific
  terms.
  
  VFLib is provided under the terms of The MIT License (MIT):

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.
*/
/*============================================================================*/

/** Add this to get the @ref vf_db module.

    @file vf_db.cpp
    @ingroup vf_db
*/

#include "AppConfig.h"

#include "vf_db.h"

#include "../vf_sqlite/vf_sqlite.h"

#if JUCE_MSVC
#pragma warning (push)
#pragma warning (disable: 4100) // unreferenced formal parmaeter
#pragma warning (disable: 4355) // 'this' used in base member
#endif

namespace vf
{
// implementation headers
#include "detail/error_codes.h"
#include "detail/statement_imp.h"
}

namespace vf
{
#include "source/blob.cpp"
#include "source/error_codes.cpp"
#include "source/into_type.cpp"
#include "source/once_temp_type.cpp"
#include "source/prepare_temp_type.cpp"
#include "source/ref_counted_prepare_info.cpp"
#include "source/ref_counted_statement.cpp"
#include "source/session.cpp"
#include "source/statement.cpp"
#include "source/statement_imp.cpp"
#include "source/transaction.cpp"
#include "source/use_type.cpp"
}

#if JUCE_MSVC
#pragma warning (pop)
#endif
