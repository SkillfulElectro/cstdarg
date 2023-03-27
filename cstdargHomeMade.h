#pragma once


/*
	so we gonna explore how cstdarg works here
*/
class Ellipsis {
	/*
		so basically first we make a object which with class type va_list
		our Ellipsis class here !
	*/
private:
	void* Ellipsis_ptr;
	// here we keep address of first ellipsis parameter of our function
public:
	template <typename noneEllipsisType>
	void setEllipsis(noneEllipsisType& last_nonEllipsis) {
		/*
			if u remember with va_start() , it would take our last none
			Ellipsis element and based on that it would give us ellipsis
			elements !

			// so what we do here is similar to that the only diff thing we do is
			that we take what is the biggest type in an parameters too !
			*			so what i mean by biggest type ?
			*				so it means double ( 8 byte ) in visual studio 2022
		*/

		void* address = &last_nonEllipsis;
		Ellipsis_ptr = static_cast<double*>(address) + 1;
		/*
			so the heart of our class is here ! how do we get the address of it?

			// if u remember that we mentioned earlier functions keeps their
			parameters in like an array and between each parameter there is
			gap as much as the the biggest type ( a lil more than that )
			element #Sponge_Bob_theory ! so if we want
			// so if want to reach to our 1st ellipsis element we will jump from
			that gap with making our address the biggest type pointer and plus it
			with one ! here it is , our 1st ellipsis element !!!
		*/
	}

	//give variable with the type which is in the ellpsis!
	// 
	// in this method user gives smth similar to that type to system deduces the type
	template<typename EllipsisType>
	EllipsisType next_arg(EllipsisType smth) {
		/*
			here we gonna walk through our array of parameters !
			what we do is 1st we ask our user for the type of the ellipsis
			and then we extract it from the array
		*/
		EllipsisType valuee = *(static_cast<EllipsisType*>(Ellipsis_ptr));
		/*
			reading value of our ellipsis element from array
		*/
		Ellipsis_ptr = static_cast<double*>(Ellipsis_ptr) + 1;
		/*
			and now jumping to next ellipsis element for next call !

			// for restarting the jumper , u have to recall setEllipsis() function
		*/

		return valuee;
	}

	// this one u provide the value to read inside of <> !
	template<typename EllipsisType>
	EllipsisType next_arg() {
		/*
			here we gonna walk through our array of parameters !
			what we do is 1st we ask our user for the type of the ellipsis
			and then we extract it from the array
		*/
		EllipsisType valuee = *(static_cast<EllipsisType*>(Ellipsis_ptr));
		/*
			reading value of our ellipsis element from array
		*/
		Ellipsis_ptr = static_cast<double*>(Ellipsis_ptr) + 1;
		/*
			and now jumping to next ellipsis element for next call !

			// for restarting the jumper , u have to recall setEllipsis() function
		*/

		return valuee;
	}
};

/*

		//CopyRight SkillFulElectro LLC***

*/	
