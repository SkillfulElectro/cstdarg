#pragma once

/*
    Exploring the Functionality of cstdarg through Custom Class: Ellipsis
*/
class Ellipsis {
    /*
        To simulate the behavior of va_list, we create an object of the Ellipsis class.
    */
private:
    void* Ellipsis_ptr;
    // Store the address of the first ellipsis parameter of our function.

public:
    template <typename noneEllipsisType>
    void setEllipsis(noneEllipsisType& last_nonEllipsis) {
        /*
            Mimicking va_start(): determine ellipsis elements based on the last non-Ellipsis element's type.
        */
        void* address = &last_nonEllipsis;
        Ellipsis_ptr = static_cast<double*>(address) + 1;
        /*
            The core of our class: calculating the address of the first ellipsis element.

            The ellipsis parameters are stored with gaps equal to the size of the largest type.
        */
    }

    // Fetch the variable with the type that corresponds to the ellipsis.
    // 
    // In this method, the user provides a sample type to help the system deduce the type.
    template<typename EllipsisType>
    EllipsisType next_arg(EllipsisType sample) {
        /*
            Iterating through our array of parameters.
            We ask the user for the ellipsis type and extract it from the array.
        */
        EllipsisType value = *(static_cast<EllipsisType*>(Ellipsis_ptr));
        /*
            Reading the value of our ellipsis element from the array.
        */
        Ellipsis_ptr = static_cast<double*>(Ellipsis_ptr) + 1;
        /*
            Moving to the next ellipsis element for the next call.
            To restart, recall the setEllipsis() function.
        */

        return value;
    }

    // This version allows you to provide the value type to be read within <>
    template<typename EllipsisType>
    EllipsisType next_arg() {
        /*
            Similar to the previous method, we traverse the array of parameters.
            User provides the ellipsis type and we extract it from the array.
        */
        EllipsisType value = *(static_cast<EllipsisType*>(Ellipsis_ptr));
        /*
            Reading the value of our ellipsis element from the array.
        */
        Ellipsis_ptr = static_cast<double*>(Ellipsis_ptr) + 1;
        /*
            Moving to the next ellipsis element for the next call.
            To restart, recall the setEllipsis() function.
        */

        return value;
    }
};

/*
    Copyright © SkillFulElectro LLC.
*/
