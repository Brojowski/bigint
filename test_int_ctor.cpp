// bigint Test Program
//
// Tests:  int constructor and output << operator.
//         uses ==
// 
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        //------------------------------------------------------
        // Test: Construct with 0
        // Setup fixture

        // Test 
        bigint* bi = new bigint(0);

        // Verify
        assert(*bi == 0);
        std::cout << "0 == ";
        std::cout << *bi;
        std::cout << std::endl;

        delete bi;
    }

    {
        //------------------------------------------------------
        // Test: Construct with 1
        // Setup fixture

        // Test 
        bigint* bi = new bigint(1);

        // Verify
        assert(*bi == 1);
        std::cout << "1 == ";
        std::cout << *bi;
        std::cout << std::endl;

        delete bi;
    }

    {
        //------------------------------------------------------
        // Test: Construct with 100000
        // Setup fixture

        // Test 
        bigint* bi = new bigint(100000);

        // Verify
        assert(*bi == 100000);
        std::cout << "100000 == ";
        std::cout << *bi;
        std::cout << std::endl;

        delete bi;
    }


    {
        //------------------------------------------------------
        // Test: Construct with two-digit value
        // Setup fixture

        // Test 
        bigint* bi = new bigint(27);

        // Verify
        assert(*bi == 27);
        std::cout << "27 ==  ";
        std::cout << *bi;
        std::cout << std::endl;

        delete bi;

        // Verify
        bi = new bigint(5006);   //Check re-assignment.
        assert(*bi == 5006);
        std::cout << "5006 ==  ";
        std::cout << *bi;
        std::cout << std::endl;

        delete bi;
    }

    {
        //------------------------------------------------------
        // Test: Construct with six-digit value
        // Setup fixture

        // Test 
        bigint* bi = new bigint(456789);

        // Verify
        assert(*bi == 456789);
        std::cout << "456789 == " << *bi << std::endl;
        delete bi;
    }
    
    std::cout << "Done testing constructor bigint(int)." << std::endl;


}

