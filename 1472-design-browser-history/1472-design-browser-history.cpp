class BrowserHistory {
public:

    // Doubly LinkedList History keep track of the URLs(strings) we have visited till now

    list<string> history ;

    // Iterator It is declared so that we can iterate over our Doubly LinkedList very easily

    list<string> :: iterator it ;

    // Initially, when the constructor is called with string homepage, we will insert the homepage into our history List and make iterator it point to the First Node

    BrowserHistory(string homepage)
    {
        // We insert homepage into our List History

        history.push_back(homepage) ;

        // We make It point to the First Node of history

        it = history.begin() ;

    }

    void visit(string url)
    {
        // Del Iterator is used to delete the previous connections of Current Node(moving foward from Current Node)

        auto del = it ;

        // We increment del so that it moves to the Next Node

        del++ ;

        // We delete all the Nodes starting from Del

        history.erase(del , history.end() ) ;

        // After that we push the new URL into our History List

        history.push_back(url) ;

        // We increment It to next Node

        it++ ;
    }

    string back(int steps)
    {
        // We need to go back to the Page by moving the given number of steps back
        // But we need to make sure we don't go beyond the First Node (pointed by history.begin() )

        while(( it != history.begin() ) && (steps--) )
        {
            it-- ;
        }

        // After we have moved the given number of steps backward, we return the string by de-referencing It

        return *it ;
    }

    string forward(int steps)
    {
        // We need to go back to the Page by moving the given number of steps forward
        // But we need to make sure we don't go beyond the Last Node (pointed by history.end() - 1 )
        // --history.end() points to the Last Node of our Doubly LinkedList

        while(( it != --history.end()) && (steps--) )
        {
            it++ ;
        }

         // After we have moved the given number of steps backward, we return the string by de-referencing It

        return *it ;

    }
};
