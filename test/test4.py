# robot_arm_control.py

# Each axis represents either a translation or rotation
axes = {
    "x": 0,    # forward/back
    "y": 0,    # left/right
    "z": 0,    # up/down
    "roll": 0, # rotate about x
    "pitch": 0,# rotate about y
    "yaw": 0   # rotate about z
}

def move_axis(axis_name, delta):
    if axis_name in axes:
        axes[axis_name] += delta
        if axes[axis_name] > 180:
            axes[axis_name] = 180
        elif axes[axis_name] < -180:
            axes[axis_name] = -180

def print_position():
    print("Current Arm Position:")
    for axis in axes:
        print(f"  {axis.upper()}: {axes[axis]}°")
    print()

# Simulated control sequence
move_axis("x", 10)
move_axis("y", -5)
move_axis("z", 15)
move_axis("roll", 45)
move_axis("pitch", -30)
move_axis("yaw", 60)

print_position()
