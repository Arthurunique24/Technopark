from django.shortcuts import render, render_to_response
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger


def init():
    questions = []
    for i in range(0, 100):
        questions.append({
            'title': 'Title in question ' + str(i),
            'id': i,
            'text': 'Text in question ' + str(i),
            'likes': 5,
            'tags': ['Java', 'Android', 'SQL'],
            'isVote': 0,
            'count_answers': 31,
            'answers': [{'text': 'answer1', 'isCorrect': 1, 'likes': 5},
                        {'text': 'answer2', 'isCorrect': 0, 'likes': 5}],
        })
    hotTags = ['Python', 'C++', 'Android']
    # bestMembers = ['Mr.Freeman', 'Dr.House', 'Bender', 'Homer', 'Rick']
    Authorized = 1
    return {'questions': questions, 'hotTags': hotTags, 'Authorized': Authorized}


def pagination(request):
    init_list = init()
    paginator = Paginator(init_list['questions'], 3)
    page = request.GET.get('page')
    try:
        articles = paginator.page(page)
    except PageNotAnInteger:
        articles = paginator.page(1)
    except EmptyPage:
        articles = paginator.page(paginator.num_pages)
    return articles


def index(request):
    init_list = init()
    return render_to_response('index.html', {'isAuthorized': init_list['Authorized'],
                                             'questions': pagination(request),
                                             'tags': init_list['hotTags']})


def ask(request):
    init_list = init()
    return render_to_response('ask.html', {'isAuthorized': init_list['Authorized'],
                                           'questions': pagination(request),
                                           'tags': init_list['hotTags']})


def question(request):
    init_list = init()
    return render_to_response('question.html', {'isAuthorized': init_list['Authorized'],
                                                'question': init_list['questions'],
                                                'tags': init_list['hotTags']})


def login(request):
    init_list = init()
    return render_to_response('login.html', {'isAuthorized': init_list['Authorized'],
                                             'questions': pagination(request),
                                             'tags': init_list['hotTags']})



def settings(request):
    init_list = init()
    return render_to_response('settings.html', {'isAuthorized': init_list['Authorized'],
                                                'questions': pagination(request),
                                                'tags': init_list['hotTags']})


def signup(request):
    init_list = init()
    return render_to_response('signup.html', {'isAuthorized': init_list['Authorized'],
                                              'questions': pagination(request),
                                              'tags': init_list['hotTags']})


def hot(request):
    init_list = init()
    return render_to_response('hotQuestions.html', {'isAuthorized': init_list['Authorized'],
                                                    'questions': pagination(request),
                                                    'tags': init_list['hotTags']})


def questionsbytag(request):
    init_list = init()
    return render_to_response('questionsbytag.html', {'isAuthorized': init_list['Authorized'],
                                                      'questions': pagination(request),
                                                      'tags': init_list['hotTags']})
