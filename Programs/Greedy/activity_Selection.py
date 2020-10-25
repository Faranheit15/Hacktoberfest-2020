"""The following implementation assumes that the activities 
are already sorted according to their finish time"""

"""Prints a maximum set of activities that can be done by a 
single person, one at a time"""
# s[]--> An array that contains start time of all activities
# f[] --> An array that contains finish time of all activities


def printMaxActivities(activity):
    print("The following activities are selected")
    activity = sorted(activity, key=lambda x: x[1])

    print("ACTIVITY", activity)

    # The first activity is always selected
    print(activity[0])
    i = 0
    # Consider rest of the activities
    for j in range(len(activity)-1):

        # If this activity has start time greater than
        # or equal to the finish time of previously
        # selected activity, then select it
        if activity[i][1] <= activity[j+1][0]:
            i = j+1
            print(activity[j+1])


# Driver program to test above function
s = [1, 3, 0, 5, 8, 5]
f = [2, 4, 6, 7, 9, 9]
activity = []
for i in range(len(s)):
    activity.append([s[i], f[i]])
printMaxActivities(activity)
