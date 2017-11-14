from django.core.management import BaseCommand
from django.contrib.auth.models import User

# from questions.models import Question
#
# class Command(BaseCommand):
#     help = 'Fill questions'
#
#     def handle(self, *args, **options):
#         fake = Factory.create()
#
#         number = int(options['number'])
#
#         users = User.objects.all()[1:]
#         for i in range(0, number):
#             q = Question()
#
#             q.title = fake.sentence(nb_words=randint(2, 4), variable_nb_words=True)
#             q.text = fake.paragraph(nb_sentences=randint(4, 17), variable_nb_sentences=True)
#             q.author = choice(users)
#             # q.rating = randint(0,1000)
#             q.save()
#
#
#
#     def add_arguments(self, parser):

