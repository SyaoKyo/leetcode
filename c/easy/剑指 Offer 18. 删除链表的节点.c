/+ACo-
+ACo- +UlFjBw- Offer 18. +UiCWZJT+iGh2hIKCcLk-
+ACo- +ftlbmlNVVBGU/ohodoRZNGMHlIhUjE4ATiqJgVIglmR2hIKCcLl2hFA8/wxbmk5JTgBOKlH9ZXBSIJZki+WCgnC5MAI-
+ACo- +j9RW3lIglmRUDnaElP6IaHaEWTSCgnC5MAI-
+ACo- +bOhhD/8aa2SYmFv5a9RTn5iYZwllOVKo-
+ACo- 
+ACo- +eTpPiw- 1:
+ACo- +j5NRZQ-: head +AD0- +AFs-4,5,1,9+AF0-, val +AD0- 5
+ACo- +j5NR+g-: +AFs-4,1,9+AF0-
+ACo- +ieORyg-: +ftlbmk9glP6IaE4tUDxOOgCg-5+AKB2hHssToxOKoKCcLn/DJCjTkhXKIwDdShOhk9gdoRR/WVwTktUDv8Mi+WU/ohoXpRT2E46- 4 -+AD4- 1 -+AD4- 9.
+ACo- 
+ACo- +eTpPiw- 2:
+ACo- +j5NRZQ-: head +AD0- +AFs-4,5,1,9+AF0-, val +AD0- 1
+ACo- +j5NR+g-: +AFs-4,5,9+AF0-
+ACo- +ieORyg-: +ftlbmk9glP6IaE4tUDxOOgCg-1+AKB2hHssTglOKoKCcLn/DJCjTkhXKIwDdShOhk9gdoRR/WVwTktUDv8Mi+WU/ohoXpRT2E46- 4 -+AD4- 5 -+AD4- 9.
+ACo-
+ACo- +i/RmDv8a-
+ACo- +mJh27k/di8GU/ohoTi2CgnC5doRQPE6STg12+FQM-
+ACo- +guVPf3Uo- C +YhY- C+-+- +i+2KAP8MT2BODZcAiYE- free +YhY- delete +iKtSIJZkdoSCgnC5-
+ACo-/
/+ACoAKg-
 +ACo- Definition for singly-linked list.
 +ACo- struct ListNode +AHs-
 +ACo-     int val+ADs-
 +ACo-     struct ListNode +ACo-next+ADs-
 +ACo- +AH0AOw-
 +ACo-/
struct ListNode+ACo- deleteNode(struct ListNode+ACo- head, int val)
+AHs-
    struct ListNode+ACo- p +AD0- head+ADs-
    if (p-+AD4-val +AD0APQ- val)
    +AHs-
        head +AD0- p-+AD4-next+ADs-
        return head+ADs-
    +AH0-
    while (p-+AD4-next +ACEAPQ- NULL)
    +AHs-
        if (p-+AD4-next-+AD4-val +AD0APQ- val)
        +AHs-
            p-+AD4-next +AD0- p-+AD4-next-+AD4-next+ADs-
            return head+ADs-
        +AH0-
        p +AD0- p-+AD4-next+ADs-
    +AH0-
    return head+ADs-
+AH0-
/+ACo-
+ACo- +YmeITH7TZ5z/GpAaj8c-
+ACo- +YmeITHUoZfb/Gg-4 ms, +VyhiQGcJ- C +Y9BOpE4tUfuNJU6G-89.93+ACV2hHUoYjc-
+ACo- +UYVbWG2IgBf/Gg-6 MB, +VyhiQGcJ- C +Y9BOpE4tUfuNJU6G-82.18+ACV2hHUoYjc-
+ACo-/