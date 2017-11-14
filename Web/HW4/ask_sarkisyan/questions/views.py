from django.shortcuts import render, render_to_response
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger

from questions.models import *
from questions.functions import *


def index(request, page='1'):
    questions = pagination(request, Question.objects.newest(), 20, page)
    questions.paginator.baseurl = "/"
    return render_to_response('index.html',
                              {'tags': randomTags(Tag), 'users': randomUsers(User), 'questions': questions,
                               'isAuthorized': True})


# def question(request, id):
#     init_list = init()
#     return render_to_response('question.html', {'isAuthorized': init_list['Authorized'],
#                                                 'questions': init_list['questions'][int(id)],
#                                                 'tags': init_list['hotTags']})
#
#
# def hot(request):
#     init_list = init()
#     return render_to_response('hotQuestions.html', {'isAuthorized': init_list['Authorized'],
#                                                     'questions': pagination(request),
#                                                     'tags': init_list['hotTags']})
#
#
# def questionsbytag(request):
#     init_list = init()
#     return render_to_response('questionsbytag.html', {'isAuthorized': init_list['Authorized'],
#                                                       'questions': pagination(request),
#                                                       'tags': init_list['hotTags']})
#
#
# def ask(request):
#     init_list = init()
#     return render_to_response('ask.html', {'isAuthorized': init_list['Authorized'],
#                                            'questions': pagination(request),
#                                            'tags': init_list['hotTags']})
#
#
# def login(request):
#     init_list = init()
#     return render_to_response('login.html', {'isAuthorized': 0,
#                                              'questions': pagination(request),
#                                              'tags': init_list['hotTags']})
#
#
# def signup(request):
#     init_list = init()
#     return render_to_response('signup.html', {'isAuthorized': 0,
#                                               'questions': pagination(request),
#                                               'tags': init_list['hotTags']})
#
#
# def settings(request):
#     init_list = init()
#     return render_to_response('settings.html', {'isAuthorized': init_list['Authorized'],
#                                                 'questions': pagination(request),
#                                                 'tags': init_list['hotTags']})
