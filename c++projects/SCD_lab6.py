# observer_pattern_elearning.py

from abc import ABC, abstractmethod
from typing import List


# ─────────────────────────────────────────
# Event Types
# ─────────────────────────────────────────

class EventType:
    NEW_LECTURE    = "new_lecture"
    DEADLINE_NEAR  = "deadline_near"
    GRADE_RELEASED = "grade_released"


# ─────────────────────────────────────────
# Observer Interface
# ─────────────────────────────────────────

class Observer(ABC):
    @abstractmethod
    def update(self, event_type: str, data: dict) -> None:
        pass


# ─────────────────────────────────────────
# Subject Interface
# ─────────────────────────────────────────

class Subject(ABC):
    @abstractmethod
    def subscribe(self, event_type: str, observer: Observer) -> None:
        pass

    @abstractmethod
    def unsubscribe(self, event_type: str, observer: Observer) -> None:
        pass

    @abstractmethod
    def notify(self, event_type: str, data: dict) -> None:
        pass


# ─────────────────────────────────────────
# Concrete Subject: E-Learning Platform
# ─────────────────────────────────────────

class ELearningPlatform(Subject):
    def __init__(self):
        self._subscribers: dict[str, List[Observer]] = {
            EventType.NEW_LECTURE:    [],
            EventType.DEADLINE_NEAR:  [],
            EventType.GRADE_RELEASED: [],
        }

    def subscribe(self, event_type: str, observer: Observer) -> None:
        self._subscribers[event_type].append(observer)

    def unsubscribe(self, event_type: str, observer: Observer) -> None:
        self._subscribers[event_type].remove(observer)

    def notify(self, event_type: str, data: dict) -> None:
        for observer in self._subscribers[event_type]:
            observer.update(event_type, data)

    # ── Platform actions ──

    def upload_lecture(self, course: str, title: str) -> None:
        print(f"\n[Platform] New lecture uploaded: '{title}' in {course}")
        self.notify(EventType.NEW_LECTURE, {"course": course, "title": title})

    def deadline_reminder(self, assignment: str, hours_left: int) -> None:
        print(f"\n[Platform] Deadline reminder: '{assignment}' due in {hours_left}h")
        self.notify(EventType.DEADLINE_NEAR, {"assignment": assignment, "hours_left": hours_left})

    def release_grades(self, assignment: str, student_name: str, grade: str) -> None:
        print(f"\n[Platform] Grades released for '{assignment}'")
        self.notify(EventType.GRADE_RELEASED, {"assignment": assignment, "student": student_name, "grade": grade})


# ─────────────────────────────────────────
# Concrete Observers
# ─────────────────────────────────────────

class Student(Observer):
    def __init__(self, name: str):
        self.name = name

    def update(self, event_type: str, data: dict) -> None:
        if event_type == EventType.NEW_LECTURE:
            print(f"  [Student - {self.name}] New lecture '{data['title']}' available in {data['course']}. Time to study!")
        elif event_type == EventType.DEADLINE_NEAR:
            print(f"  [Student - {self.name}] Hurry! '{data['assignment']}' is due in {data['hours_left']} hours.")
        elif event_type == EventType.GRADE_RELEASED:
            if data["student"] == self.name:
                print(f"  [Student - {self.name}] Your grade for '{data['assignment']}': {data['grade']}")


class Teacher(Observer):
    def __init__(self, name: str):
        self.name = name

    def update(self, event_type: str, data: dict) -> None:
        if event_type == EventType.NEW_LECTURE:
            print(f"  [Teacher - {self.name}] Lecture '{data['title']}' successfully published to {data['course']}.")
        elif event_type == EventType.GRADE_RELEASED:
            print(f"  [Teacher - {self.name}] Grades for '{data['assignment']}' are now visible to students.")


class AcademicAdvisor(Observer):
    def __init__(self, name: str):
        self.name = name

    def update(self, event_type: str, data: dict) -> None:
        if event_type == EventType.DEADLINE_NEAR:
            print(f"  [Advisor - {self.name}] Alert: '{data['assignment']}' deadline in {data['hours_left']}h. Check in with students.")
        elif event_type == EventType.GRADE_RELEASED:
            print(f"  [Advisor - {self.name}] Grades released for '{data['assignment']}'. Student: {data['student']}, Grade: {data['grade']}")


class Parent(Observer):
    def __init__(self, name: str, child_name: str):
        self.name = name
        self.child_name = child_name

    def update(self, event_type: str, data: dict) -> None:
        if event_type == EventType.DEADLINE_NEAR:
            print(f"  [Parent - {self.name}] Reminder: Your child {self.child_name} has '{data['assignment']}' due in {data['hours_left']}h.")
        elif event_type == EventType.GRADE_RELEASED:
            if data["student"] == self.child_name:
                print(f"  [Parent - {self.name}] {self.child_name}'s grade for '{data['assignment']}': {data['grade']}")


# ─────────────────────────────────────────
# Main
# ─────────────────────────────────────────

if __name__ == "__main__":
    platform = ELearningPlatform()

    # Create subscribers
    student1 = Student("Alice")
    student2 = Student("Bob")
    teacher  = Teacher("Dr. Smith")
    advisor  = AcademicAdvisor("Ms. Johnson")
    parent   = Parent("Mr. Brown", child_name="Alice")  # optional subscription

    # Subscribe to events
    platform.subscribe(EventType.NEW_LECTURE,    student1)
    platform.subscribe(EventType.NEW_LECTURE,    student2)
    platform.subscribe(EventType.NEW_LECTURE,    teacher)

    platform.subscribe(EventType.DEADLINE_NEAR,  student1)
    platform.subscribe(EventType.DEADLINE_NEAR,  student2)
    platform.subscribe(EventType.DEADLINE_NEAR,  advisor)
    platform.subscribe(EventType.DEADLINE_NEAR,  parent)   # optional

    platform.subscribe(EventType.GRADE_RELEASED, student1)
    platform.subscribe(EventType.GRADE_RELEASED, student2)
    platform.subscribe(EventType.GRADE_RELEASED, teacher)
    platform.subscribe(EventType.GRADE_RELEASED, advisor)
    platform.subscribe(EventType.GRADE_RELEASED, parent)   # optional

    # Trigger events
    platform.upload_lecture("CS101", "Introduction to Recursion")
    platform.deadline_reminder("Assignment 2", hours_left=24)
    platform.release_grades("Assignment 2", student_name="Alice", grade="A")
    platform.release_grades("Assignment 2", student_name="Bob",   grade="B+")