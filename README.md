***LBYARCH S12 Machine Project - Tyrone Angelo Uy, Kendrick Mikhael Pua*** 

**Kernel Execution Time Analysis** 

Machine Hardware Specifications
Processor: AMD Ryzen 9 5900HS
RAM: 40gb

![Screenshot 2024-04-02 225409](https://github.com/oAloof/lbyarch_saxpy/assets/105725179/a25e0735-b9fc-49cb-89df-d257c2cb4f64)

We automated the testing and averaged the time it takes for each version to compute the values by using a loop. The system initially asks for the size of the arrays it wants to create (in this case, we utilized 2^20, 2^24, 2^28), then uses a randomizer function to create an array filled with random values until it reaches the desired size. The above image shows how we implemented it. 

![image](https://github.com/oAloof/lbyarch_saxpy/assets/105725179/1582e177-7a26-4fea-b55c-4537993c6367)

**Debug Mode**
This image represents the average time (out of 30) used in running the kernels for both C and Assembly versions, and proof that both the Assembly and C program output the same values. In the above screenshot, we test using the sizes 2^20, 2^24, 2^28. The results show that on average, the assembly version runs faster.

![image4](https://github.com/oAloof/lbyarch_saxpy/assets/105725179/b74c8739-1313-4c46-9081-e28d96abf6be)

**Release Mode**
This image represents the average time used in running the kernels for both versions, and proof that both the Assembly and C program output the same values. In the above screenshot, the results show that rather than having a clear winner, C is faster in 2 cases, and Assembly is faster in 1.

**Analysis of the Kernel Performance**

Visual Studio's Debug Mode and Release Mode differ by Debug Mode including debug information while Release Mode applies various optimizations while running the code. In debug mode, it makes sense due to the fact that assembly does not go through a compiler, instead its directly made into CPU instructions.

Modern compilers provide a wide range of optimizations that makes code compilation faster. By using Release Mode, it activates all of these more modern optimizations (mostly for C) which changes the runtime. Although in this case assembly was still faster in 1 case, if you were to further test it, C would come out to be faster.
