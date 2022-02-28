## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
What is a Red Black Tree

### What Does it Look Like?
- First, we need to know what an RB search tree looks like. Judging from the name, there will be leaf color-coding involved, and we will get to understand the importance of that specific type of color-coding and why it is vital to the tree implementation. Now, here is a picture of a lovely RB search tree!
![Example of RED_BLACK_TREES](https://miro.medium.com/max/1400/1*ZRWKUc_Cxi6C5iwHDl622Q.png "Example of RED_BLACK_TREES")
#### The Five Rules:
**1**-**Roots are black**: 
- We elaborated in the last blog what the root of a tree is. In our case, the root of the tree has to be black. This makes it so that the tree can have a self-organizing and rotating mechanism to make it a well-balanced tree.
**2-Nodes are either Black or Red:**
- The second rule is that every single node in the middle of the tree has the possibility of being either red or black, as opposed to other components in the tree where they can only be one color, aka the root. With that in mind, it is not just the case where it can be, but it is the case where it has to be. Every single node in the middle of the tree needs to have one of these color codings.
**3- All red nodes have to have two black children**:
- Every single red node in the tree needs to have two black children underneath it. In the process of adding more nodes, one of two things happens to ensure this rule is being met. Either the tree rotates to accommodate the main rule of binary trees, or the color of the nodes change!
**4- All leaves have to be black**:
- Leaves are the nodes at the end of the tree. These leaves are required to be black. In the diagram above you can see that we add NIL nodes at the end of the tree which are important to this rule and the following one. The NIL leaves are always there at the end but are not necessarily visualized when the tree is output.
**5- Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes:**
- If you look at the diagram above, you will see that every path a node can take has the same number of black nodes.