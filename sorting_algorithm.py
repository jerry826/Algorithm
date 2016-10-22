
# coding: utf-8

# In[1]:

import math 
import random
import sys   
sys.setrecursionlimit(10000000)


def exchange(l,i,j):
    temp=l[i]
    l[i]=l[j]
    l[j]=temp
    return l

# insertion sort

def insert_sort(l):
    n = len(l)
    for i in range(n):
        min_index = i
        for j in range(i+1,n):
            if l[j] < l[min_index]:
                min_index=j
        l = exchange(l,i,min_index)
    return(l)
    

# shell sort

def shell_sort(l):
    n = len(l)
    d = int(n/2)
    while d>0:
        for i in range(d,n):
            temp = l[i]
            j = i
            while (j>=d and temp<l[j-d]):
                l[j] = l[j-d]
                j = j-d
            l[j] = temp
        d =int(d/2)
    return(l)
        


# merge sort


def merge(left, right):
    i = 0
    j = 0
    result = []
    while i< len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result


def merge_sort(l):
    if len(l)<=1:
        return(l)
    else:
        num = int(len(l)/ 2)
        left = merge_sort(l[:num])
        right = merge_sort(l[num:])
        return merge(left, right)

# quick sort
def quick_sort(l):
    if len(l)<=1:
        return l
    else:
        greater = []
        less = []
        key =l.pop(random.randint(0,len(l)-1))
        for i in range(len(l)):
            if l[i] > key:
                greater.append(l[i])
            else:
                less.append(l[i])
        
        return quick_sort(less)+[key]+quick_sort(greater)

    
def radix_sort(l,radix=10):
    k = int(math.ceil(math.log(max(l),radix)))
    bucket = [[] for i in range(radix)]

    for i in range(1,k+1):
        for j in l:
            bucket[ int( ( j/(radix**(i-1))) % (radix)) ].append(j)
        del l[:]
        for z in bucket:
            l += z
            del z[:]
    return(l)



n = 1000000
l = [ random.randint(0, 2**31-1) for i in range(n)]
# %time l1 = (insert_sort(l.copy()))
get_ipython().magic('time l2 = (shell_sort(l.copy()))')
get_ipython().magic('time l3 = (merge_sort(l.copy()))')
get_ipython().magic('time l4 = (quick_sort(l.copy()))')
get_ipython().magic('time l5 = (radix_sort(l.copy()))')


# In[78]:

l2==l3==l4==l5


# In[ ]:



