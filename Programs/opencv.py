import cv2
import numpy as np 

drawing=False # true if mouse is pressed

print('Instructions:\n\t1. Press P to Predict Number\n\t2. Press R to Reset screen\n\t3. Press Q to quit')

# mouse callback function
def draw(event,x,y,flags,param):
    global current_x,current_y,drawing

    # If the left mouse key is continiously pressed then drawing will be set to True.
    if event==cv2.EVENT_LBUTTONDOWN:
        drawing=True
        current_x,current_y=x,y

    # If drawing == True and mouse is moved then line will be drawn.
    elif event==cv2.EVENT_MOUSEMOVE:
        if drawing==True:
            cv2.line(im,(current_x,current_y),(x,y),(255,255,255),5)
            current_x = x
            current_y = y

    # If left mouse key is released then drawing will be set to False.
    elif event==cv2.EVENT_LBUTTONUP:
        drawing=False
        cv2.line(im,(current_x,current_y),(x,y),(255,255,255),5)
        current_x = x
        current_y = y
    return x,y    


# Creating a black image to draw numbers on it.
im = np.zeros((128,128,1))

# create a window.
cv2.namedWindow("InputWindow")

# Sets mouse handler for the specified window i.e. 'InputWindow'
cv2.setMouseCallback('InputWindow',draw)
while(1):

    # The default dtype for np.zeros is float. We need to change it to uint8.

    # Displays the image on the specified window.
    cv2.imshow('InputWindow',im)

    k = cv2.waitKey(1)
    if k == ord('q'):
        break
    elif k == ord('r'):
        im = np.zeros((128,128,1))
    elif k == ord('p'):
        img = cv2.resize(im,(28,28))
        img = img.reshape(1,1,28,28)
        img= torch.from_numpy(img)
        model.eval()
        with torch.no_grad():
          pred=model(img.float()).argmax()
        # cv2.imshow('Output',img.reshape(28,28))
        print(f"Drawn digit is: {pred.item()}")

cv2.destroyAllWindows()
