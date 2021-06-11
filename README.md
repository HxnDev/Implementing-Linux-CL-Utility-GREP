# Implementing-Linux-CL-Utility-GREP
CL = Command Line

## Part 1:

### Algorithm:

**Step1:**

```
First of all, we need to preprocess the pattern string before we start searching for it in the main
text. For this we need to construct a LPS array (longest proper prefix) which corresponding and of same
size to the pattern string.

(i) a_lps[i] will store the length of maximum matching proper prefix of the pattern array.
(ii) We will loop through the a_pattern array and find maximum matching proper for each
index.
```
**Step2:**

```
Now we will be searching for the pattern “a_pattern[]” in the string text[] with the help of the
a_lps [] array we just generated.

(i) We will use the value in the a_lps[] array to decide the next characters to be matched.
The main strategy is to not match the character that we know will anyway will match.
(ii) Now we will start with comparing a_pattern[] with text[] for the very first character.
(iii) We will keep comparing the array is the specific range until an array character by
character until a mismatch is found. If not found, we will move to the next range in the
text[] array.
(iv) The movement from one range in the text[] to the other range in text [] is done by using
a_lps[].
(v) We will repeat until the full string is searched.
```
### Complexity:

```
Preprocessing complexity time complexity:

O(n) ( Where n is the length of the text input.)

Worst time complexity:

O(m) ( Where m is the length of the string pattern.)
```


#### All the files have been commented for your ease. Furthermore you may also add further comments if you may.

## For further queries contact me at : chhxnshah@gmail.com

