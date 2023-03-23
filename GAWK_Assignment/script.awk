function prntree(nor,K,L,R)
{
    printf("\n \tGoing to read tree with %d nodes\n\n",nor);
    for (i=1; i<=nor; i++)
    {
        printf("%10s :   ID = %4d  Left child = %10s Right child = %10s \n",K[i],i,K[L[i]],K[R[i]])
    }
}

function findroot(nor,P,K)
{
    for (i=1; i<=nor; i++)
    {
        if (P[i]==0){
            break;
        }
    }
    return i;
}

function inorder(rootid,L,R,K)
{
    if (rootid==0)
        return;
    inorder(L[rootid],L,R,K);
    printf("\t\t%s\n", K[rootid]);
    inorder(R[rootid],L,R,K);
}

BEGIN{
    FS = ":"
    nor=0
    noc=0
    pc=1 #present count
    H["test"]=0
}

{
    if (NR==1) { 
        nor = int($1);
        for (i=1; i<=nor; i++) { L[i]=0; R[i]=0; P[i]=0;}
    }
    else{
        parent= $1 ;
        noc=split($2,child,",") ;
        lchild=child[1] ;
        rchild=child[2] ;
        if (parent in H){
            if (lchild != "") {
                if (lchild in H)
                {
                    L[H[parent]]=H[lchild];
                    P[H[lchild]]=H[parent];
                }
                else{
                    H[lchild]=pc;
                    K[H[lchild]]=lchild;
                    pc++;
                    L[H[parent]]=H[lchild];
                    P[H[lchild]]=H[parent];
                }
            }
            if (rchild != "") { 
                if (rchild in H)
                {
                    R[H[parent]]=H[rchild];
                    P[H[rchild]]=H[parent]; 
                }
                else{
                    H[rchild]=pc;
                    K[H[rchild]]=rchild;
                    pc++;
                    R[H[parent]]=H[rchild];
                    P[H[rchild]]=H[parent];
                }
            }
        }
        else {
            H[parent]=pc;
            K[H[parent]]=parent;
            pc++;
            if (lchild != "") {
                if (lchild in H)
                {
                    L[H[parent]]=H[lchild];
                    P[H[lchild]]=H[parent];
                }
                else{
                    H[lchild]=pc;
                    K[H[lchild]]=lchild;
                    pc++;
                    L[H[parent]]=H[lchild];
                    P[H[lchild]]=H[parent];
                }
            }
            if (rchild != "") { 
                if (rchild in H)
                {
                    R[H[parent]]=H[rchild];
                    P[H[rchild]]=H[parent]; 
                }
                else{
                    H[rchild]=pc;
                    K[H[rchild]]=rchild;
                    pc++;
                    R[H[parent]]=H[rchild];
                    P[H[rchild]]=H[parent];
                }
            }
        }
    }
}
    
END{
    prntree(nor,K,L,R)
    i=findroot(nor,P,K)
    printf("\n \tThe root node has ID %d and key '%s'\n",i,K[i])
    printf("\n\tInorder listing of the keys:\n\n")
    inorder(i,L,R,K)
}
