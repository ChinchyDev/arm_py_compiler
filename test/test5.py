# robotic_arm_simulator.py

import time
import math

class Servo:
    def __init__(self, name, min_angle=-180, max_angle=180):
        self.name = name
        self.angle = 0
        self.min_angle = min_angle
        self.max_angle = max_angle

    def move_to(self, target_angle):
        if target_angle < self.min_angle or target_angle > self.max_angle:
            raise ValueError(f"{self.name} angle out of bounds")
        print(f"[Servo {self.name}] Moving to {target_angle}°")
        # Simulate delay
        time.sleep(0.1)
        self.angle = target_angle

    def __repr__(self):
        return f"{self.name}: {self.angle:.1f}°"

class RobotArm:
    def __init__(self):
        self.axes = {
            "x": Servo("X"),
            "y": Servo("Y"),
            "z": Servo("Z"),
            "roll": Servo("Roll", -90, 90),
            "pitch": Servo("Pitch", -90, 90),
            "yaw": Servo("Yaw", -180, 180)
        }

    def move_axis(self, axis, angle):
        if axis not in self.axes:
            raise ValueError("Unknown axis")
        self.axes[axis].move_to(angle)

    def move_to_pose(self, pose_dict):
        print("\n--- Moving to New Pose ---")
        for axis, angle in pose_dict.items():
            self.move_axis(axis, angle)
        self.report_position()

    def report_position(self):
        print(">> Current Robot Arm Position:")
        for axis in self.axes:
            print(f"  {self.axes[axis]}")
        print()

    def go_home(self):
        print("\n[Returning to Home Position]")
        for axis in self.axes:
            self.move_axis(axis, 0)

# Example usage
if __name__ == "__main__":
    arm = RobotArm()

    home_pose = {
        "x": 0, "y": 0, "z": 0,
        "roll": 0, "pitch": 0, "yaw": 0
    }

    pick_pose = {
        "x": 10, "y": -5, "z": 20,
        "roll": 15, "pitch": -10, "yaw": 45
    }

    place_pose = {
        "x": -15, "y": 10, "z": 25,
        "roll": -20, "pitch": 5, "yaw": -30
    }

    arm.move_to_pose(pick_pose)
    time.sleep(1)
    arm.move_to_pose(place_pose)
    time.sleep(1)
    arm.go_home()
