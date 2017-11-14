from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
import numpy as np


def pagination(request, data, count, page):
    paginator = Paginator(data, count)
    get = request.GET.get('page')
    if get:
        page = int(get)
    try:
        paginator_datas_list = paginator.page(int(page))
    except PageNotAnInteger:
        data_list = paginator.page(1)
    except EmptyPage:
        paginator_datas_list = paginator.page(paginator.num_pages)
    return paginator_datas_list


def randomTags(tag):
    tags = []
    for i in range(tag.objects.count()):
        tags.append(str(tag.objects.get(id=i + 1)))
    np.random.shuffle(tags)
    return tags[:10]


def randomUsers(user):
    users = []
    for i in range(user.objects.count()):
        users.append(str(user.objects.get(id=i + 1)))
    np.random.shuffle(users)
    return users[:5]
