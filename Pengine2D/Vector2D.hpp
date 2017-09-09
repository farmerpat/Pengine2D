//
//  Vector2D.hpp
//  Pengine2D
//
//  Created by Patrick Connelly on 9/8/17.
//  Copyright © 2017 Patrick Connelly. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <string>

namespace PVector2D {
    /*
     * Example usage:
     *
     * Vector2D<int> myVect (2,3);
     * printf("x: %d\n", myVect.getX());
     * printf("y: %d\n", myVect.getY());
     *
     * Vector2D<float> myOtherVect (2.4, 3.3);
     * printf("x: %f\n", myOtherVect.getX());
     * printf("y: %f\n", myOtherVect.getY());
     *
     */

    template <class T>
    class Vector2D {
    public:
        Vector2D (T x, T y) {
            this->_the_vector[0] = x;
            this->_the_vector[1] = y;
        }

        T getX (void) {
            return this->_the_vector[0];
        }

        T getY (void) {
            return this->_the_vector[1];
        }

        void setX (T newX) {
            this->_the_vector[0] = newX;
        }

        void setY (T newY) {
            this->_the_vector[1] = newY;
        }

    private:
        T _the_vector[2];

    };
}

#endif /* Vector2D_hpp */
