/*------------------------------------------------------------------------------

    Copyright (c) 2010 Sourcefabric O.P.S.
 
    This file is part of the Campcaster project.
    http://campcaster.sourcefabric.org/
 
    Campcaster is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
  
    Campcaster is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with Campcaster; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
------------------------------------------------------------------------------*/
#ifndef RpcRescheduleTest_h
#define RpcRescheduleTest_h

#ifndef __cplusplus
#error This is a C++ include file
#endif


/* ============================================================ include files */

#ifdef HAVE_CONFIG_H
#include "configure.h"
#endif

#include <cppunit/extensions/HelperMacros.h>

#include "LiveSupport/Core/Ptr.h"
#include "LiveSupport/Core/SessionId.h"

#include "BaseTestMethod.h"

namespace LiveSupport {
namespace Scheduler {

using namespace LiveSupport::Core;

/* ================================================================ constants */


/* =================================================================== macros */


/* =============================================================== data types */

/**
 *  Unit test to test the removeFromSchedule XML-RPC call.
 *
 *  @see SchedulerDaemon
 */
class RpcRescheduleTest : public BaseTestMethod
{
    CPPUNIT_TEST_SUITE(RpcRescheduleTest);
    CPPUNIT_TEST(simpleTest);
    CPPUNIT_TEST(negativeTest);
    CPPUNIT_TEST(currentlyPlayingTest);
    CPPUNIT_TEST_SUITE_END();

    private:

        /**
         *  A session ID from the authentication client login() method.
         */
        Ptr<SessionId>::Ref                     sessionId;

    protected:

        /**
         *  Simple smoke test.
         *
         *  @exception CPPUNIT_NS::Exception on test failures.
         */
        void
        simpleTest(void)                        throw (CPPUNIT_NS::Exception);

        /**
         *  Simple negative test.
         *
         *  @exception CPPUNIT_NS::Exception on test failures.
         */
        void
        negativeTest(void)                      throw (CPPUNIT_NS::Exception);

        /**
         *  A test to see if the currently playing entry can be reschuled
         *  (should not)
         *
         *  @exception CPPUNIT_NS::Exception on test failures.
         */
        void
        currentlyPlayingTest(void)              throw (CPPUNIT_NS::Exception);

    public:
        
        /**
         *  Set up the environment for the test case.
         */
        void
        setUp(void)                             throw (CPPUNIT_NS::Exception);

        /**
         *  Clean up the environment after the test case.
         */
        void
        tearDown(void)                          throw (CPPUNIT_NS::Exception);
};


/* ================================================= external data structures */


/* ====================================================== function prototypes */


} // namespace Scheduler
} // namespace LiveSupport

#endif // RpcRescheduleTest_h
