from django.shortcuts import render

from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt

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


@csrf_exempt
def getpost(request):
    response =  "Post:" \
                "<form method='post'>" \
                "<input type='text' name = 'text'>" \
                "<input type='submit' value='Submit'>" \
                "</form>"
    if request.method == 'POST':
        response += "<h1>Post data:</h1>"
        response += "Value = %s <br>" % (request.POST.get('text'))
    elif request.method == 'GET':
        if request.GET:
            response += "<h1>Get data:</h1>"
            for key,value in request.GET.items():
                if len(value) == 1:
                    response += "%s = %s <br>" % (key, value[0])
                else:
                    response += "%s = %s <br>" % (key, value)
    return HttpResponse(response, content_type="text/html", status=200)