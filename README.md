# redblack2

note that nodes with an equal key can be on either side of eachother.
this is because when we rotate we are not keeping the strong gurntees we have on insertion

testing seems to indicate that some cases in the source I used for refrence https://www.geeksforgeeks.org/deletion-in-red-black-tree/ can never happen. also added an explanation to why I think thats the case. 

there is also a lot I am borrowing from https://github.com/niedong/stl_rbtree/blob/master/src/rbtree.h specifcly the genuies idea that is_nil and color can be 2 bytes on the struct is amazing. 
I think I screwed it up by using 'B' and 'R' instead of 1 and 0 but the basic premise is that it lets the compiler load these values into a 16 byte register and you can check for either just the color in the 1 byte secssion OR you can check for black and non nil in the same run by looking at the 2 byte secssion.

I think a lot more can be done to optimize things. there is a lot of use of the rotation functions thats probably not justified. I am not even sure the compiler catches that a lot of those memory assiments are useless.