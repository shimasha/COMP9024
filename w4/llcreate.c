void showLL(NodeT *list)
{
    NodeT *p;
    for (p = list; p != NULL; p = p->next)
    {
        printf("%d", p->data);
        if (p->next != NULL)
        {
            printf("-->");
        }
    }
    printf("\n");
}

// JoinLL function

NodeT *joinLL(NodeT *list, int v)
{
    // create a new node and allocate memory
    NodeT *nNode = (NodeT *)malloc(sizeof(NodeT));

    // checking the memory alocation
    if (nNode == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nNode->data = v; // assign the int v to the new code
    nNode->next = NULL;

    if (list == NULL)
    {
        return nNode;
    }

    list->next = joinLL(list->next, v); // using recursing we add the new node
    return list;
}

// main function

int main()
{
    NodeT *outLL = NULL;

    printf("Enter an integer: ");

    int integer;
    while (scanf("%d", &integer) == 1)
    {
        outLL = joinLL(outLL, integer);

        printf("Enter an integer: ");
    }

    // Check if the list is not empty
    if (outLL != NULL)
    {
        printf("Done. List is ");
        showLL(outLL); // Display the contents
    }
    else
    {
        printf("Done.\n");
    }

    // Free the memory allocated for the linked list
    freeLL(outLL);

    return 0;
}

// gcc -Wall -Werror -std=c11 -o llcreate llcreate.c
//  ./llcreate   9024 dryrun llcreate