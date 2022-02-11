## Project description

The insurance company wants to protect its clients' data. My task is to develop a data transforming algorithm that would make it hard to recover personal information from the transformed data. This is called data masking, or data obfuscation. I am also expected to prove that the algorithm works correctly. Additionally, the data should be protected in such a way that the quality of machine learning models doesn't suffer.
- construct a theoretical proof using properties of models and the given task;
- formulate an algorithm for this proof;
- check that the algorithm is working correctly when applied to real data.

I will use a simple method of data masking, based on an invertible matrix.

### Data description
**Features**: insured person's gender, age, salary, and number of family members.<br>
**Target**: number of insurance benefits received by the insured person over the last five years.
