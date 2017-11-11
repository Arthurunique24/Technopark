from django.conf.urls import url
from . import views

# from questions.views import AboutView

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^question/(?P<id>\d+)/?$', views.question, name='question'),
    url(r'^ask/', views.ask, name='ask'),
    url(r'^login/', views.login, name='login'),
    url(r'^settings/', views.settings, name='settings'),
    url(r'^signup/', views.signup, name='signup'),
    url(r'^hot/', views.hot, name='hot'),
    url(r'^questionsbytag/', views.questionsbytag, name='questionsbytag')
]
