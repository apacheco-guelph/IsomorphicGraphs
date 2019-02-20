# IsomorphicGraphs

## APPROACH

To solve for isomorphic graphs, the program has to prove that 2 graphs
are the same or different. This problem falls under the **p v np** problems as it can't be solved under a sufficent amount of time. 
> However currently the best way to look at the problem and solve it within a resonibile time
is to solve that they are not the same graph.

## Solving difference

The fastest approach found for me was the idea that both graphs do not contain either:
- more nodes than the other
- have more connections than the other
- do not have the same ammount of degrees per nodes

## Future Approach

The next approach to this problem would be to build a struct that can hold the nodes:
- Name
- Number of Connections
- The names of their connections (and the names pointer to that struct)
```
struct{
  pointName;
  int* connectedNums;
  *pointer[];
}
```

From this we would need to make a list of the structs and be able to traverse through it
via their connections then be able to access their data from their connections pointer.
With this working conecpet we can then make 2 different graphs and traverse them proving 
that they are either isomorphic or non isomorphic.


