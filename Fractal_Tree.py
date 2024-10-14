import turtle

# the turtle window
window = turtle.Screen()
window.bgcolor("white")

# turtle object
fractal_tree = turtle.Turtle()
fractal_tree.shape("turtle")
fractal_tree.speed(10)  # Fast drawing

#  draw fractal tree
def draw_tree(branch_length, t):
    if branch_length > 5:
        # Move turtle forward
        t.forward(branch_length)
        # Recursively draw right branch
        t.right(20)
        draw_tree(branch_length - 15, t)
        # Recursively draw left branch
        t.left(40)
        draw_tree(branch_length - 15, t)
        # Return the turtle to original orientation
        t.right(20)
        t.backward(branch_length)

# Initial position of turtle
fractal_tree.left(90)  # Point upwards
fractal_tree.penup()
fractal_tree.backward(100)  # Move down the screen
fractal_tree.pendown()

# finally drawing the fractal tree
draw_tree(100, fractal_tree)

# Closing the window when clicked
window.exitonclick()
