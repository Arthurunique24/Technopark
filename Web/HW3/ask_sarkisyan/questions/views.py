from django.shortcuts import render

QUESTIONS = {
    '1': {'id': 1, 'title': 'I`m your dream', 'text': 'I`m your dream, make you real'},
    '2': {'id': 2, 'title': 'I`m your eyes', 'text': 'I`m your eyes when you must steal'},
    '3': {'id': 3, 'title': 'I`m your pain', 'text': 'I`m your pain when you can`t feel'},
}


def index(request):
    return render(request, 'index.html', {'questions': QUESTIONS.values()})


def ask(request):
    return render(request, 'ask.html', {'questions': QUESTIONS.values()})


def login(request):
    return render(request, 'login.html', {'questions': QUESTIONS.values()})


def question(request):
    return render(request, 'question.html', {'questions': QUESTIONS.values()})


def settings(request):
    return render(request, 'settings.html', {'questions': QUESTIONS.values()})


def signup(request):
    return render(request, 'signup.html', {'questions': QUESTIONS.values()})


def hot(request):
    return render(request, 'hotQuestions.html', {'questions': QUESTIONS.values()})


def questionsbytag(request):
    return render(request, 'questionsbytag.html', {'questions': QUESTIONS.values()})
