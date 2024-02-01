# About

    • C program of micro-version of Facebook using Hash Tables and Linked Lists.

### Input

Program accepts from input a sequence of commands of the following forms, one command to a line, such as:

    • P ⟨name⟩ – Create a person record of the specified first name. You may
    assume that no two people have the same first name.
    • F ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are friends.
    • U ⟨name1⟩ ⟨name2⟩ — Record that the two specified people are no longer
    friends.
    • L ⟨name⟩ — Print out the friends of the specified person.
    • Q ⟨name1⟩ ⟨name2⟩ — Check whether the two people are friends. If so,
    print “Yes”; if not, print “No”
    • X – terminate the program.

### Operation Time Complexity

    • The command “L” takes time proportional to the number of friends that the person has. 
    • The command “U” should execute in time proportional to the sum of the friends that the two named people have. 
    • The commands “P”, “F”, and “Q” execute in a constant time.

NOTE: All these commands execute in time that is independent of the total number of people in
the system.

### Run Specifications

    • All the entries saved in memory.
    • Program compiles using gcc on a unix/lunix machine. 

